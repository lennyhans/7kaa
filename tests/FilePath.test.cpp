#include "doctest.h"
#include <stdio.h>
#include <stdlib.h>
#include <FilePath.h>


void * FilePathTestInit(){
	return NULL;
}

void * FilePathTestDeinit(){
	return NULL;
}


TEST_CASE("Test FilePath structure") {
	FilePath target;
	const char* expected_value = "PATH";
	char* overflow_value;
	char char_value = 'a';
	int MAX_LENGTH = FilePath::MAX_FILE_PATH;
	int OK = 0,
		ERROR = 1;
		
	// Prepare a overflow char random value
	overflow_value = (char*) malloc( MAX_LENGTH +1);
	for(int i =0, l = MAX_LENGTH; i <= l; i++){
		strcat( overflow_value, &char_value);
	}
	
	// Require empty init value
	REQUIRE(strlen(target) == 0);
	
	
	SUBCASE("Test value on FilePath(char *)"){
		FilePath expected(expected_value);
		CHECK(strlen(expected.str_buf) == strlen(expected_value));
	}
	
	SUBCASE("Check max size of structure"){
		// Useful?
		int path_size = 260;
		CHECK(FilePath::MAX_FILE_PATH == path_size);
	}
	
	SUBCASE("Check add function"){
		SUBCASE("With value"){
			target += expected_value;
			CHECK(strlen(target.str_buf) == strlen(expected_value));
			CHECK(target.error_flag == OK);
		}
		
		SUBCASE("With two values"){
			target += expected_value;
			target += expected_value;
			CHECK(strlen(target.str_buf) == strlen(expected_value) + strlen(expected_value));
			CHECK(target.error_flag == OK);
		}
		
		SUBCASE("With emtpy"){
			const char* empty = "";
			target += empty;
			CHECK(strlen(target.str_buf) == 0 );
			CHECK(target.error_flag == OK);
		}
		
		SUBCASE("With null variable"){
			const char* null_pointer;
			target += null_pointer;
			CHECK( strlen(target.str_buf) == 0 );
			CHECK(target.error_flag == OK);
		}
		
		SUBCASE("With overflow value"){
			int pre_add_length = strlen(target.str_buf);
			target += overflow_value;
			CHECK(target.error_flag == ERROR);
			CHECK( strlen(target.str_buf) == pre_add_length);
		}
		
		SUBCASE("With overflow value and then OK"){
			int pre_add_length = strlen(target.str_buf);
			target += overflow_value;
			CHECK(target.error_flag == ERROR);
			CHECK( strlen(target.str_buf) == pre_add_length);
			// Should clean error after another 'OK' usage?
			target += expected_value;
			CHECK( strlen(target.str_buf) == strlen(expected_value));
			CHECK_MESSAGE(target.error_flag == OK, "The last add works (aparently), so why the error?");
		}
	}
	
	SUBCASE("Check assign function"){
		SUBCASE("With value"){
			target = expected_value;
			CHECK(strlen(target.str_buf) == strlen(expected_value));
			//CHECK(target.str_buf == expected_value);
			CHECK(target.error_flag == OK);
		}
		
		SUBCASE("With emtpy"){
			const char* empty = "";
			target = empty;
			CHECK(strlen(target.str_buf) == 0 );
			CHECK(target.error_flag == OK);
		}
		
		SUBCASE("With null variable"){
			const char* null_pointer;
			target = null_pointer;
			CHECK( strlen(target.str_buf) == 0 );
			CHECK(target.error_flag == OK);
		}
		
		
		SUBCASE("With overflow value"){
			int pre_add_length = strlen(target.str_buf);
			target = overflow_value;
			REQUIRE(target.error_flag == ERROR);
			CHECK( strlen(target.str_buf) == pre_add_length);
		}
		
		SUBCASE("With overflow value and then OK"){
			int pre_add_length = strlen(target.str_buf);
			target = overflow_value;
			REQUIRE(target.error_flag == ERROR);
			CHECK( strlen(target.str_buf) == pre_add_length);
			// Should clean error after another 'OK' usage?
			target = expected_value;
			CHECK( strlen(target.str_buf) != pre_add_length);
			CHECK( strlen(target.str_buf) == strlen(expected_value));
			CHECK_MESSAGE(target.error_flag == OK, "The recently assign aparently works");
		}
	}
	
	if(overflow_value != NULL)
		free(overflow_value);
}
