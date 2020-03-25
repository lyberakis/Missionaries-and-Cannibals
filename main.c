#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int lm=3, lc=3, rm=0, rc=0;
char b[2], before[2];
bool side=true;

bool theCheck(){
    if (lm<0 || lc<0 || rm<0 || rc<0){
        printf("This move cannot be done\n");
        return false;
    }else if ((lm!=0 && lm<lc) || (rm!=0 && rm<rc)){
        printf("This move causes failure. Let's try another one.\n");
        return false;
    }
    return true;
}

int main()
{
    bool check=true;

    while (rm!=3 || rc!=3){
        if (side==true){ //transferring from left to right
            printf("Finding best match for transferring people from left to right...\n");
            if (before[0]!='m' || before[1]!='c'){
                printf("Trying one missionary and one cannibal.\n");  //CASE MC
                lm--;
                lc--;
                rm++;
                rc++;
                check=theCheck();
                if (check==false){
                    lm++;
                    lc++;
                    rm--;
                    rc--;
                }
            }else
                check=false;
            if (check==false){
                check=true;
                if (before[0]!='m' || before[1]!='e'){
                    printf("Trying one missionary.\n");   //CASE M
                    lm--;
                    rm++;
                    check=theCheck();
                    if (check==false){
                        lm++;
                        rm--;
                    }
                }else
                    check=false;
                if (check==false){
                    check=true;
                    if (before[0]!='m' || before[1]!='m'){
                        printf("Trying two missionaries.\n"); //CASE MM
                        lm=lm-2;
                        rm=rm+2;
                        check=theCheck();
                        if (check==false){
                            lm=lm+2;
                            rm=rm-2;
                        }
                    }else
                        check=false;
                    if (check==false){
                        check=true;
                        if (before[0]!='c' || before[1]!='c'){
                            printf("Trying two cannibals.\n"); //CASE CC
                            lc=lc-2;
                            rc=rc+2;
                            check=theCheck();
                            if (check==false){
                                lc=lc+2;
                                rc=rc-2;
                            }
                        }else
                            check=false;
                        if (check==false){
                            check=true;
                            if (before[0]!='c' || before[1]!='e'){
                                printf("Trying one cannibal.\n"); //CASE C
                                lc--;
                                rc++;
                                check=theCheck();
                                if (check==false){
                                    lc++;
                                    rc--;
                                }
                            }else
                                check=false;
                            if (check==false){
                                printf("SOMETHING WENT WRONG\n");
                                break;
                            }else{
                                printf("CHOOSING C\n");
                                before[0]='c';
                                before[1]='e';
                                side=false;
                            }
                        }else{
                            printf("CHOOSING CC\n");
                            before[0]='c';
                            before[1]='c';
                            side=false;
                        }
                    }else{
                      printf("CHOOSING MM\n");
                      before[0]='m';
                      before[1]='m';
                      side=false;
                    }
                }else{
                  printf("CHOOSING M\n");
                  before[0]='m';
                  before[1]='e';
                  side=false;
                }
            }else{
              printf("CHOOSING MC\n");
              before[0]='m';
              before[1]='c';
              side=false;
            }
        }else{  //transferring from right to left
            printf("Finding best match for transferring people from right to left...\n");
            if (before[0]!='m' || before[1]!='c'){
                printf("Trying one missionary and one cannibal.\n");  //CASE MC
                rm--;
                rc--;
                lm++;
                lc++;
                check=theCheck();
                if (check==false){
                    lm--;
                    lc--;
                    rm++;
                    rc++;
                }
            }else
                check=false;
            if (check==false){
                check=true;
                if (before[0]!='m' || before[1]!='e'){
                    printf("Trying one missionary.\n");   //CASE M
                    rm--;
                    lm++;
                    check=theCheck();
                    if (check==false){
                        rm++;
                        lm--;
                    }
                }else
                    check=false;
                if (check==false){
                    check=true;
                    if (before[0]!='m' || before[1]!='m'){
                        printf("Trying two missionaries.\n"); //CASE MM
                        rm=rm-2;
                        lm=lm+2;
                        check=theCheck();
                        if (check==false){
                            lm=lm-2;
                            rm=rm+2;
                        }
                    }else
                        check=false;
                    if (check==false){
                        check=true;
                        if (before[0]!='c' || before[1]!='c'){
                            printf("Trying two cannibals.\n"); //CASE CC
                            lc=lc+2;
                            rc=rc-2;
                            check=theCheck();
                            if (check==false){
                                lc=lc-2;
                                rc=rc+2;
                            }
                        }else
                            check=false;
                        if (check==false){
                            check=true;
                            if (before[0]!='c' || before[1]!='e'){
                                printf("Trying one cannibal.\n"); //CASE C
                                rc--;
                                lc++;
                                check=theCheck();
                                if (check==false){
                                    rc++;
                                    lc--;
                                }
                            }else
                                check=false;
                            if (check==false){
                                printf("SOMETHING WENT WRONG\n");
                                break;
                            }else{
                                printf("CHOOSING C\n");
                                before[0]='c';
                                before[1]='e';
                                side=true;
                            }
                        }else{
                            printf("CHOOSING CC\n");
                            before[0]='c';
                            before[1]='c';
                            side=true;
                        }
                    }else{
                      printf("CHOOSING MM\n");
                      before[0]='m';
                      before[1]='m';
                      side=true;
                    }
                }else{
                  printf("CHOOSING M\n");
                  before[0]='m';
                  before[1]='e';
                  side=true;
                }
            }else{
              printf("CHOOSING MC\n");
              before[0]='m';
              before[1]='c';
              side=true;
            }
        }
    }
    printf("Success!!!!!!!!!!!!!");
    return 0;
}
