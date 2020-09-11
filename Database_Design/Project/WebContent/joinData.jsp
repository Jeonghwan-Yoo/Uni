<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ page import ="java.sql.*"%>

<% request.setCharacterEncoding("UTF-8"); %>

<%
	String driver="com.mysql.jdbc.Driver";//mysql jdbc드라이버(필수)
	String url ="jdbc:mysql://localhost:3306/trip";//마지막 부분을 본인의 스키마로
	String dbId="root"; //데이터베이스 ID
	String dbPw="";//데이터베이스 PW
	
	String id=request.getParameter("id");
	String password=request.getParameter("password");
	
	PreparedStatement pstmt=null;
	Connection conn=null;//데이터베이스 연결쪽 관련 코드
	String str="";
	
	 try{
		 Class.forName(driver);//JDBC드라이버가 실제로 적용되는 부분
		 conn=DriverManager.getConnection(url, dbId, dbPw);//데이터 베이스에 연결을 위해서 URL, ID, PW가 사용되는 부분
		 
		 String sql="insert into member(id, password) values(?,?)";//26번 이용해 미리 컴파일 후 위치홀더 각각의 위치에 28,29 지정값 대치
		 pstmt=conn.prepareStatement(sql);

		 pstmt.setString(1, id);
		 pstmt.setString(2, password);
		 pstmt.executeUpdate();//실행(insert문 -> executeUpdate()메소드 사용)
		 
		 str="1";//성공
		 
	 }catch(Exception e){
		e.printStackTrace();
		str="0";//실패
	 }finally{
		 if(pstmt != null)
			 try{pstmt.close();}catch(SQLException sqle){}
		 if(conn != null)
			 try{conn.close();}catch(SQLException sqle){}
		 
	 }
	%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<link rel="stylesheet" href="./make.css">
	<title>회원가입데이터</title>
</head>
<body>
<%
	if(str=="1"){
		out.println("<script>");
		out.println("alert('회원가입이 되었습니다. 로그인해주세요.')");
		out.println("location.href='loginMain.jsp'");
		out.println("</script>");
	}else{
		out.println("<script>");
		out.println("alert('이미 존재하는 아이디입니다.')");
		out.println("location.href='loginMain.jsp'");
		out.println("</script>");
	}
%>
</body>
</html>