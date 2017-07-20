CXXFLAGS=-g -Wall -Wextra -std=c++14 -MD
LDFLAGS=-pthread -ldl

default: weightroom


libsqlite3.a:
	$(CC) -g -O2 -c source/sqlite3/sqlite3.c
	ar -rcs libsqlite3.a sqlite3.o


hiberlite_src=\
	source/hiberlite/BeanLoader.cpp\
	source/hiberlite/BeanUpdater.cpp\
	source/hiberlite/ChildKiller.cpp\
	source/hiberlite/CppModel.cpp\
	source/hiberlite/Database.cpp\
	source/hiberlite/ModelExtractor.cpp\
	source/hiberlite/Registry.cpp\
	source/hiberlite/shared_res.cpp\
	source/hiberlite/SQLiteStmt.cpp\
	source/hiberlite/Visitor.cpp\

hiberlite_obj=$(hiberlite_src:.cpp=.o)

libhiberlite.a: $(hiberlite_obj)
	ar -rcs libhiberlite.a $(hiberlite_obj)

weightroom_src=\
	source/main.cpp\
	source/food.cpp	\
	source/fooddatabase.cpp\
	source/workout.cpp\
	

weightroom_obj=$(weightroom_src:.cpp=.o)

weightroom: libsqlite3.a libhiberlite.a $(weightroom_obj) $(weightroom_src)
	$(CXX) $(CXXFLAGS) -o weightroom $(weightroom_obj) libsqlite3.a libhiberlite.a $(LDFLAGS)

clean:
	-rm -f weightroom
	-rm -f $(weightroom_obj) $(weightroom_src:.cpp=.d)
	-rm -f libsqlite3.a sqlite3.o
	-rm -f libhiberlite.a
	-rm -f $(hiberlite_obj)

-include $(weightroom_src:.cpp=.d) $(hiberlite_obj:.o=.d)