package chap08_prac08;

import java.io.*;

public class FileSize {

	public static void main(String[] args) {
		File file = new File("c:\\");
		File [] files = file.listFiles(); // c:\에 있는 디렉터리와 파일의 리스트 얻기 
		
		long bigSize = 0;
		File bigFile =null;
		for(int i=0; i<files.length; i++) { // 전체 파일에 대해
			File f = files[i];
			if(!f.isFile()) // 디렉터리인 경우 넘어감
				continue;
			
			long size = f.length(); // 파일인 경우 길이 얻어내기 
			if(bigSize < size) {
				bigSize = size;
				bigFile = f;
			}
		}

		if(bigFile == null) // 모두 디렉터리인 경우
			System.out.println("파일은 없습니다");
		else
			System.out.println("가장 큰 파일은 " + bigFile.getPath() + " " + bigSize + "바이트");
	}

}

