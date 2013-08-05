
## ==========================================================================================
## FUNCTION : autoload_functions
## PURPOSE  : To check functions that are required, try to autoload them if NOT YET defined
##
## exit 1 - if any required function cannot be autoloaded (meaning, not found in standard 
##          library location.
## TODO     : Allow commenting out req_func for easy management
##			: Allow path where function would be autoloaded, first parameter should be allocated
##             for this purpose
## ==========================================================================================
function autoload_functions {
    local req_func=$*
    local ret_val=0
    local logfile=
	
    ## FDEBUG - Log to file the autoloaded functions to cross-check
    ##          against those defined inside calling script
    ##    1 - activate debugging
    ##    0 - disable debugging
    local FDEBUG=0

    [ -z $LOGFILE_autoload_functions ] && logfile=$LOGFILE_autoload_functions || logfile=$logs_rootdir/autoload_functions.log
    local timestamp_log=`date`

    [ $FDEBUG ] && echo "START: $timestamp_log" >> $logfile 
    ## iterate through all $req_func, set $ret_val to 1
    ## if any required function cannot be autoloaded
    for each_func in $req_func; do
        [ $FDEBUG ] && echo $each_func >> $logfile

        ## if function undefined, try to auto-include (reference from specified location)
        type $each_func &> /dev/null || source $lib_rootdir/${each_func}.bash.inc

        ## recheck, ensure it has been defined.
        type $each_func &> /dev/null || (echo "ERROR: Missing required ${each_func}"|$TEE_BIN -a $logfile; ret_val=1)        
    done

    [ $FDEBUG ] && echo "END: $timestamp_log" >> $logfile
    [ $FDEBUG ] && echo '----------'          >> $logfile

    ## abort (exit 1) if any required func cannot be autoloaded
    [ $ret_val -eq 1 ] && exit $ret_val
}