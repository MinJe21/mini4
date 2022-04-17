
#include "manager.h"

int addMenu(Menu *s){
    getchar();
    printf("메뉴명은?:");
    scanf("%[^\n]s", s->name);

    getchar();
    printf("메뉴설명은?:");
    scanf("%[^\n]s", s->explain); 

    getchar();
    printf("중량은?:");
    scanf("%[^\n]s", s->weight);

    printf("가격은?:");
    scanf("%d", &s->price);

    printf("배송방법은?(1.새벽배송/2.택배배송)(숫자선택):");
    scanf("%d", &s->method);

    return 1;
}

void readMenu(Menu s){
    printf("\t제품명: %s\n\t설명: %s\n\t중량: %s\n\t가격: %d\n\t배송방법: %d", s.name, s.explain, s.weight, s.price, s.method);
}

void listMenu(Menu *s, int count){
    for(int i = 0; i < count; i++){
        if(s[i].price == -1){
            continue;
        }
        printf("\n%2d", i+1);
        readMenu(s[i]);
    }
    printf("\n");
}

int selectDataNo(Menu *s, int count){
    int no;
    listMenu(s, count);
    printf("번호는?(취소 0) ");
    scanf("%d", &no);
    
    return no;
}

int updateMenu(Menu *s){
    getchar();
    printf("메뉴명은?:");
    scanf("%[^\n]s", s->name);

    getchar();
    printf("메뉴설명은?:");
    scanf("%[^\n]s", s->explain);

    getchar();
    printf("중량은?:");
    scanf("%[^\n]s", s->weight);

    printf("가격은?:");
    scanf("%d", &s->price);

    printf("배송방법은?(1.새벽배송/2.택배배송)(숫자선택):");
    scanf("%d", &s->method);

    return 1;
}

int deleteMenu(Menu *s){
    s->price= -1;
    s->method = -1;

    return 1;
}

void saveData(Menu *s, int count){
    FILE *fp;
    fp = fopen("fruit.txt", "wt");
    for(int i =0; i < count; i++){
        if(s[i].price == -1) continue;
        fprintf(fp,"제품명: %s\n설명: %s\n중량: %s\n가격: %d\n배송방법: %d", s->name, s->explain, s->weight, s->price, s->method);
    }
    fclose(fp);
    printf("=> 저장됨!\n");
}

int loadData(Menu *s){
    int count = 0, i = 0;
    FILE *fp;
    if (fp = fopen("fruit.txt", "rt")){
        fgets(s->name,255, fp);
        s->name[strlen(s->name)-1] = '\0';
        fgets(s->explain,255, fp);
        s->explain[strlen(s->explain)-1] = '\0';
        fgets(s->weight,255, fp);
        s->weight[strlen(s->weight)-1] = '\0';
        fscanf(fp, "%d", &s->price);
        fscanf(fp, "%d", &s->method);
        fclose(fp);
        printf("\n=> 로딩 성공!\n");
    }else{
        printf("\n=> 파일 없음...\n");
    }
    return i;
}

void searchName(Menu *s, int count){
    int scnt = 0;
    char search[20];

    printf("검색할 이름?:");
    scanf("%s", search);

    for(int i=0; i < count; i++){
        if(s[i].price == -1) continue;
        if(strstr(s[i].name, search)){
            printf("%2d", i+1);
            readMenu(s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}


int selectMenu(){
    int menu;
    printf("\n*** 과일택배배송 ***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("5. 메뉴저장\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

