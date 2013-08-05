## sqlQuery - given query (stored in $1) does the query to standard mysql server defined in $conf_rootdir/db.cf.inc

function sqlQuery {
	## ensure that db vars are properly defined
	[ -z "$mysql_server"   ] && (echo 'sqlQuery() - $mysql_server cannot be blank'   | $TEE_BIN -a $logfile; exit 1)
	[ -z "$mysql_database" ] && (echo 'sqlQuery() - $mysql_database cannot be blank' | $TEE_BIN -a $logfile; exit 1)
	[ -z "$mysql_user"     ] && (echo 'sqlQuery() - $mysql_user cannot be blank'     | $TEE_BIN -a $logfile; exit 1)		
	[ -z "$mysql_password" ] && (echo 'sqlQuery() - $mysql_password cannot be blank' | $TEE_BIN -a $logfile; exit 1)		
	[ -z "$1"              ] && (echo 'sqlQuery() - full query cannot be blank'      | $TEE_BIN -a $logfile; exit 1)
	
	output=$(echo "$1" | $MYSQL_BIN --host $mysql_server --database $mysql_database --user $mysql_user --password=${mysql_password} --skip-column-name)
	echo "$output"
}