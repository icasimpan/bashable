## ====================================================================================================
## FILENAME: autoloader.bash.inc
## PURPOSE : controller (mediator) script between the models(individual functions) and view(bin/autoloader.sh)
##           This should be sourced from bin/bashable.sh
## ====================================================================================================

##
## $rootdir and $lib_rootdir should be defined in main script(bin/bashable.sh). Defined here for default just in case it's not defined.
##
[ -z $rootdir ] && rootdir=$HOME/bashable
[ -z $lib_rootdir ] && lib_rootdir=$rootdir/lib

logs_rootdir=$rootdir/logs
conf_rootdir=$rootdir/conf

source $conf_rootdir/common_vars.cf.inc
source $lib_rootdir/autoload_functions.bash.inc  ## mandatory sourcing. Otherwise, dependencies can't be checked/autoloaded - casimism

functions_to_autoload="
sqlQuery
"
autoload_functions "$functions_to_autoload"