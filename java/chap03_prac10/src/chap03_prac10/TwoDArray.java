package chap03_prac10;

public class TwoDArray {
	public static void main (String[] args) {
		int intArray[][] = new int[4][4];

		// 배열의 모든 원소를 0으로 초기화 
		for (int i=0; i<intArray.length; i++)
			for (int j=0; j<intArray[i].length; j++)
				intArray[i][j] = 0;

		int num = 0;
		while (num < 10) { // 10개만 랜덤한 정수 생성
			int row = (int)(Math.random()*4); // 배열의 행 인덱스 생성
			int col = (int)(Math.random()*4); // 배열의 열 인덱스 생성
			
			if (intArray[row][col] != 0) // 배열 원소가 0이 아니면 이미 값이 저장된 원소이므로 건너뜀
				continue;
			else { 
				intArray[row][col] = (int) Math.round(Math.random()*9 + 1);
				num++; // 생성된 숫자 갯수 증가
			}
		}
		
		// 2차원 배열 출력
		for (int i=0; i<intArray.length; i++) {
			for (int j=0; j<intArray[i].length; j++)
				System.out.print(intArray[i][j] + "\t");
			System.out.println();
		}
	}
}
