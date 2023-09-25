#!/bin/bash
var=$(git clean -f -d $1 -x)
echo $var
