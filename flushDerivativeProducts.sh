#!/bin/bash
var=$(git clean -f -d ./build ./TestingProjects/common ./NitroInject_AIC205.sln $1 -x **.vcxproj **.vcxproj.filters **.vcxproj.user )
echo $var
