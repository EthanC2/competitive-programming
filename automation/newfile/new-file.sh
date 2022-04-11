#! /bin/bash

# Summary: 
# Dependencies: none
# Alias: 'newfile'

function show_usage()
{
    echo "Usage: newfile -l <prog lang> -fn <filename>" &>2
}

function parse_arguments()
{
   local l_triggered=0
   local fn_triggered=0

    while getopts l:fn: opt; do
        case $opt in
            l)
                prog_lang=$(echo $OPTARG | tr [:upper:] [:lower:])
                l_triggered=1
                ;;

            fn)
                filename=$OPTARG
                fn_triggered=1
                ;;

            *)
                echo Unknown error
                exit 2
                ;;
        esac
    done

    if [[ l_triggered -ne 1 || fn_triggered -ne 1 ]]; then
        show_usage
        exit 1
    fi
}
# # # # # # # # # # # # #
#  BEGINNING OF SCRIPT  #
# # # # # # # # # # # # #

# 1. Parse commandline arguments
#parse_arguments
set -o noclobber

prog_lang=$1
filename=$2

case $prog_lang in 
    "c") 
        suffix="c"
        linenumber=5
        ;;

    "cc"|"cpp"|"c++")
        suffix="cpp"
        linenumber=27
        ;;

    "rs"|"rust")
        suffix="rs"
        linenumber=4
        ;;

    "py"|"python") 
        suffix="py"
        linenumber=2
        ;;

    *) 
        echo error: unknown filetype
        exit 1
        ;;
esac

cp /home/"$USER"/.scripts/main-templates/main."$suffix" "$PWD"/"$filename"."$suffix"
vim "$PWD"/"$filename"."$suffix" +"$linenumber" -c 'startinsert'
