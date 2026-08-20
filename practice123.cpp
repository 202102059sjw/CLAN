#include <stdio.h>

int main(void)
{
	int age;
	int is_transfer;
	int fare;
	int balance;


	printf("===대중교통 요금 결제 시스템===\n");

	printf("나이를 입력하세요: ");
	if (scanf_s("%d", &age) != 1 || age < 0) {
		printf("[오류] 올바른 나이를 입력해주세요.");
		return 1;
	}

	printf("환승 대상입니까?(환승:1, 일반:0 ): ");
	scanf_s("%d", &is_transfer);

	printf("교통카트 잔액을 입력하세요: ");
	scanf_s("%d", &balance);

	//나이에 따른 기본 요금 계산
	if (age <= 5) {
		fare = 0;
	}
	else if (age <= 12) {
		fare = 500;
	}
	else if (age <= 18) {
		fare = 800;
	}
	else if (age >= 65) {
		fare = 0;
	}
	else {
		fare = 1400;
	}

	//환승 적용 시 요금 0원 처리
	
	if (is_transfer == 1 && fare > 0) {
		fare = 0;
		printf("\n[안내] 환승입니다\n");
	}
	if (balance < fare) {
		printf("[경고] 잔액이 부족합니다! (현재 잔액: %d원  /  필요 요금:%d)\n", balance, fare);
	}
	else {
		balance -= fare;
		printf("\n[처리 완료] 결제 요금: %d", fare);
		printf("[남은 잔액]%d원\n", balance) ;
	}

}