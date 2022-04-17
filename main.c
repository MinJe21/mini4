#include <stdio.h>
#include <string.h>
#include "manager.h"

int main(){
    Menu slist[100];
    int count = 0, menu;
    int result = 0;
    int index = 0;
 
    count = loadData(slist);
    index = count;
#ifdef DEBUG
    printf("=>DEBUG MODE");
#endif
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count > 0){
                listMenu(slist, index);    
            }
        }
        else if (menu == 2){
            count += addMenu(&slist[index++]); 
        }
        else if (menu == 3){
            int no = selectDataNo(slist, index);
            if(no == 0){
                printf("취소됨\n");
                continue;
            }
            updateMenu(&slist[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(slist, index);
            if(no == 0){
                printf("취소됨\n");
                continue;
            }
            int delete;
            printf("정말로 삭제하시겠습니까?(삭제 1)");
            scanf("%d", &delete);
            if(delete == 1){
                if(deleteMenu(&slist[no-1])){
                    count--;
                }
            }
        } 
        else if(menu == 5){
            saveData(slist, index);
        }
	else if(menu == 6){
            searchName(slist, index);
	}
    }
    printf("종료됨!\n");
    return 0;
}
