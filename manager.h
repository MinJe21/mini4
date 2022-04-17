#include <stdio.h>
#include <string.h>

typedef struct{
    char name[20]; // 제품명
    char explain[200]; //설명
    char weight[20]; //중량
    int price; // 가격
    int method; //배송방법
} Menu;

int addMenu(Menu *s);//메뉴에 제품 추가

void readMenu(Menu s);//추가된 메뉴 읽기

void listMenu(Menu *s, int count);//메뉴 리스트화하기

int selectDataNo(Menu *s, int count);//번호 선택하기(삭제 및 업데이트)

int updateMenu(Menu *s);// 메뉴 수정

int deleteMenu(Menu *s);// 메뉴 삭제

void saveData(Menu *s, int count);//파일저장

int loadData(Menu *s);//파일불러오기

void searchName(Score *s, int count);//이름 서칭

int selectMenu();//기본 메뉴바
