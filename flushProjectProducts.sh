#!/bin/bash
var=$(git clean -f -d ./build ./NitroInject_AIC205.sln $1 -x )
echo $var
