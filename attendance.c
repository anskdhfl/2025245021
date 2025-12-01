#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "attendance.h"

Attendance list[MAX_ATT];
int count = 0;


void add_attendance() {

    if (count >= MAX_ATT) {
        printf("저장 공간이 부족합니다.\n");
        return;
    }

    Attendance a;

    printf("날짜 입력 (YYYY-MM-DD): ");
    scanf("%10s", a.date);

    printf("학생 이름: ");
    scanf("%31s", a.name);

    printf("과목명: ");
    scanf("%31s", a.course);

    printf("출결 상태 (0:결석, 1:지각, 2:출석): ");
    scanf("%d", &a.status);

    list[count] = a;
    count++;

    printf("출결 정보가 저장되었습니다.\n\n");

}

void list_attendance() {
    
    if (count == 0) {
        printf("저장된 출결 정보가 없습니다.\n\n");
        return;
    }

    printf("\n===== 출결 목록 =====\n");
    for (int i = 0; i < count; i++) {
        printf("%d) %s | %s | %s | ",
            i + 1, list[i].date, list[i].name, list[i].course);

        if (list[i].status == STATUS_PRESENT) printf("출석\n");
        else if (list[i].status == STATUS_LATE) printf("지각\n");
        else printf("결석\n");
    }
    printf("====================\n\n");

}

void show_stats() {
    
    if (count == 0) {
        printf("통계를 낼 정보가 없습니다.\n\n");
        return;
    }

    int present = 0, late = 0, absent = 0;

    for (int i = 0; i < count; i++) {
        if (list[i].status == STATUS_PRESENT) present++;
        else if (list[i].status == STATUS_LATE) late++;
        else absent++;
    }

    int total = present + late + absent;

    printf("\n===== 출결 통계 =====\n");
    printf("총 기록: %d\n", total);
    printf("출석: %d (%.1f%%)\n", present, (present * 100.0) / total);
    printf("지각: %d (%.1f%%)\n", late, (late * 100.0) / total);
    printf("결석: %d (%.1f%%)\n", absent, (absent * 100.0) / total);
    printf("=====================\n\n");

}

void search_by_name() {
    if (count == 0) {
        printf("검색할 출결 정보가 없습니다.\n\n");
        return;
    }

    char key[32];
    printf("검색할 학생 이름: ");
    scanf("%31s", key);

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].name, key) == 0) {
            printf("%d) %s | %s | %s | ",
                i + 1, list[i].date, list[i].name, list[i].course);

            if (list[i].status == STATUS_PRESENT) printf("출석\n\n");
            else if (list[i].status == STATUS_LATE) printf("지각\n\n");
            else printf("결석\n\n");

            found = 1;
        }
    }

    if (found == 0)
        printf("해당 학생의 출결 정보가 없습니다.\n");
}