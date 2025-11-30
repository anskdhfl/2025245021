#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "attendance.h"

void print_menu() {
    printf("===== 출결 관리 프로그램 =====\n");
    printf("1. 출결 입력\n");
    printf("2. 출결 목록 출력\n");
    printf("3. 출결 통계 확인\n");
    printf("4. 학생 이름 검색\n");
    printf("0. 종료\n");
    printf("==============================\n");
}



int main(void) {
    int choice;

    while (1) {   // 프로그램을 반복 실행하는 무한 루프
        print_menu();
        printf("메뉴 선택: ");
        scanf("%d", &choice);

        if (choice == 1) add_attendance();
        else if (choice == 2) list_attendance();
        else if (choice == 3) show_stats();
        else if (choice == 4) search_by_name();
        else if (choice == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 입력입니다.\n\n");
        }
    }

    return 0;
}