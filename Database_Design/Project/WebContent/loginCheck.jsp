<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ page import ="java.sql.*"%> 

<% request.setCharacterEncoding("UTF-8"); %>

<%
	String driver="com.mysql.jdbc.Driver"; //mysql jdbc드라이버(필수)
	String url ="jdbc:mysql://localhost:3306/trip"; //마지막 부분을 본인의 스키마로
	String dbId="root"; //데이터베이스 ID
	String dbPw=""; //데이터베이스 PW
	
	String id=request.getParameter("id");
	String password=request.getParameter("password");
	
	PreparedStatement pstmt=null;
	Connection conn=null;//데이터베이스 연결쪽 관련 코드
	ResultSet rs=null;
	
	 try{
		 Class.forName(driver);//JDBC드라이버가 실제로 적용되는 부분(데이터베이스와 연결하기 위해 DriverManager에 등록)
		 conn=DriverManager.getConnection(url, dbId, dbPw);//데이터 베이스에 연결을 위해서 URL, ID, PW가 사용되는 부분(DriverManager 객체로부터 Connection 객체를 얻어온다.)
		 
		 String sql="select id,password from member where id=?";
		 pstmt=conn.prepareStatement(sql);

		 pstmt.setString(1, id);
		 rs=pstmt.executeQuery();
		 
		 if(rs.next()){
			 String rId=rs.getString("id");
			 String rPassword=rs.getString("password");
			 if(id.equals(rId)&&password.equals(rPassword)){
				 session.setAttribute("MasterLoginID",id);
%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
		<link rel="stylesheet" href="./make.css">
</head>
<body>
	로그인 성공! 반갑습니다!<br/><br/>
	<input type="button" value="로그인 상태" onclick="location.href='login_ok.jsp'"/>
	<input type="button" value="MAP" onclick="location.href='map.jsp'"/>
</body>				
</html>
<%
			}else{
				out.println("<script>");
				out.println("alert('비밀번호를 다시 확인해주세요.')");//비밀번호가 틀린 경우
				out.println("location.href='loginMain.jsp'");
				out.println("</script>");
			 }
			}else{
				out.println("<script>");
				out.println("alert('아이디를 다시 확인해주세요.')");//회원가입이 되어 있지 않은 경우
				out.println("location.href='loginMain.jsp'");
				out.println("</script>");
			}
		}catch(Exception e){
			e.printStackTrace();//예외가 발생하면 예외를 추적해 예외가 발생한 과정을 표시
		}finally{
			if(rs != null)
				try{rs.close();}catch(SQLException sqle){}
			if(pstmt != null)
				try{pstmt.close();}catch(SQLException sqle){}
			if(conn != null)
				try{conn.close();}catch(SQLException sqle){}
		}
		
	%>
