%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%%
[0-9]+(\.[0-9]+)?([eE][0-9]+)? {yyval.f = atof(yytext); return NUM;}
[-+()*/] {return yytext[0];}
[ \t\f\v\n] {;}
%%

int yywarp() {return -1;}
