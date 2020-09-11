package chap02_prac06;

import java.util.Scanner;

public class ThreeSixNine {
	public static void main(String args[]) {
		int num, count = 0;
		Scanner scanner = new Scanner(System.in);
		System.out.print("1~99 사이의 정수를 입력하시오>>");
		num = scanner.nextInt();
		if (num >= 1 && num <= 99) {
			int a, b;
			a = num / 10; // 10의 자리에서 3,6,9, 검사
			b = num % 10; // 1의 자리에서 3,6,9 검사
			if (a != 0 && a % 3 == 0)
				count++; // 십의 자리 정수에 3,6,9중 하나가 있는 경우 numberOf369 증가
			if (b != 0 && b % 3 == 0)
				count++; // 1의 자리 정수에 3,6,9중 하나가 있는 경우 numberOf369 증가
			
			if (count == 2) System.out.println("박수짝짝");
			else if (count == 1) System.out.println("박수짝");
			else System.out.println("박수 없음");				
		} 
		else
			System.out.println("숫자가 범위를 벗어났습니다.");
		
		scanner.close();
	}
}
