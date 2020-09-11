<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.DriverManager" %>
<%@ page import="java.sql.Connection" %>
<%@ page import="java.sql.PreparedStatement" %>
<%@ page import="java.sql.ResultSet" %>
<%@ page import="java.sql.DriverManager" %>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>아프리카&중동</title>
</head>
<body>
<form action="haeggul.jsp" method="get">
<input type="submit" value="가나" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="가봉" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="감비아" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="기니" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="기니비사우" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="나미비아" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="나이지리아" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="남수단" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="남아프리카공화국" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="니우에" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="니제르" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="라이베리아" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="레바논" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="레소토" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="르완다" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="리비아" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="마다가스카르" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="말라위" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="말리" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="모로코" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="모리셔스" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="모리타니" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="모잠비크" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="바레인" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="베냉" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="보츠와나" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="부룬디" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="부르키나파소" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="사우디아라비아" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="상투메프린시페" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="세네갈" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="세이셸" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="소말리아" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="수단" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="스와질랜드" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="시리아" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="시에라리온" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="아랍에미리트" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="알제리" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="앙골라" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="에리트레아" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="에티오피아" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="예멘" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="오만" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="요르단" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="우간다" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="이라크" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="이란" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="이스라엘" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="이집트" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="잠비아" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="적도기니" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="중앙아프리카공화국" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="지부티" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="짐바브웨" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="차드" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="카메룬" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="카보베르데" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="카타르" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="케냐" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="코모로" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="코트디부아르" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="콩고" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="공고민주공화국" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="쿠웨이트" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="탄자니아" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="토고" name="name" onClick="location.href='haeggul.jsp'">
<input type="submit" value="튀니지" name="name" onClick="location.href='haeggul.jsp'">
</form>
</body>
</html>