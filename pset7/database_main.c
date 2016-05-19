#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "prob1.h"

int main(int argc, char * argv[]) {

	/* part (a): execute the first three SQL queries */
	// const char sql[] = "SELECT * FROM movies WHERE ProductionYear < 1950";
	// const char sql[] = "SELECT * FROM movies WHERE Format == \"VHS\"";
	// const char sql[] = "SELECT * FROM movies WHERE Language == \"Spanish\"";

	/* part (b, c, d): use this SQL query to read the entire table */
	const char sql[] = "SELECT * FROM movies";

	if (argc < 2) {
		fprintf(stderr,"Error: database name not specified!\n");
		return 1;
	}

	char * database_name = argv[1];
	sqlite3 * database;
	char *zErrMsg = NULL;

	const char* data = "Callback function called";

	if (sqlite3_open(database_name, &database)){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(database));
		exit(0);
	}else {
		fprintf(stderr, "Opened database successfully\n");
	}

	sqlite3_exec(database, sql, display_result, "Callback function called", &zErrMsg);

	sqlite3_close(database);

	return 0;
}
