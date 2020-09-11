package Project;

import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.w3c.dom.Document;

import java.io.IOException;
import java.net.URL;
import java.net.URLConnection;
import java.net.URLEncoder;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

public class haeggul{
	
	String ConnectionString = "jdbc:mysql://localhost:3306/trip?verifyServerCertificate=false&useSSL=true";
	String Id = "root";
	String Password = "";		
	String Classname = "com.mysql.jdbc.Driver";
	
	Connection con = null;
    PreparedStatement pstmt = null;   
	ResultSet rs=null;
	String sql="";
	String id="";
	String name="";
	String continent="";
	String basic="";
	String img="";
	String contact="";
	String img2="";

	//getter setter
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getContinent() {
		return continent;
	}
	public void setContinent(String continent) {
		this.continent = continent;
	}
	public String getBasic() {
		return basic;
	}
	public void setBasic(String basic) {
		this.basic = basic;
	}
	public String getImg() {
		return img;
	}
	public void setImg(String img) {
		this.img = img;
	}
	public String getContact() {
		return contact;
	}
	public void setContact(String contact) {
		this.contact = contact;
	}
	public String getImg2() {
		return img2;
	}
	public void setImg2(String img2) {
		this.img2 = img2;
	}
	
	public ArrayList getAddress() throws Exception{
		
		int resultCnt= -1;
		
		//3가지 공공데이터 URL받기, 리스트로 저장
		
		ArrayList list = new ArrayList();		
		String bUrl = "http://apis.data.go.kr/1262000/CountryBasicService/getCountryBasicInfo?serviceKey=";
		String cUrl = "http://apis.data.go.kr/1262000/ContactService/getContactInfo?serviceKey=";
		String aUrl = "http://apis.data.go.kr/1262000/TravelWarningService/getTravelWarningInfo?serviceKey=";
		String key="";
		
		try{
			int count =getCount();
			Class.forName(Classname);
			con = DriverManager.getConnection(ConnectionString, Id, Password);
			//id를 받아오기위한 부분
			sql = "select id from haeggul; "; 
  			pstmt = con.prepareStatement(sql);
  			rs = pstmt.executeQuery();	
  			while(rs.next())
			{
  				id = rs.getString("id");
			}
			String btotalUrl=bUrl+key+"&id="+id;
			String ctotalUrl=cUrl+key+"&id="+id;
			String atotalUrl=aUrl+key+"&id="+id;
			
			//파싱부분
			URL url1 = new URL(btotalUrl);
			URLConnection connection1 = url1.openConnection();
			DocumentBuilderFactory objDocumentBuilderFactory1 = DocumentBuilderFactory.newInstance();
			DocumentBuilder objDocumentBuilder1 =  objDocumentBuilderFactory1.newDocumentBuilder();
			Document doc1 =  (Document) objDocumentBuilder1.parse(connection1.getInputStream());
			URL url2 = new URL(ctotalUrl);
			URLConnection connection2 = url2.openConnection();
			DocumentBuilderFactory objDocumentBuilderFactory2 = DocumentBuilderFactory.newInstance();
			DocumentBuilder objDocumentBuilder2 =  objDocumentBuilderFactory2.newDocumentBuilder();
			Document doc2 =  (Document) objDocumentBuilder2.parse(connection2.getInputStream());
			URL url3 = new URL(atotalUrl);
			URLConnection connection3 = url3.openConnection();
			DocumentBuilderFactory objDocumentBuilderFactory3 = DocumentBuilderFactory.newInstance();
			DocumentBuilder objDocumentBuilder3 =  objDocumentBuilderFactory3.newDocumentBuilder();
			Document doc3 =  (Document) objDocumentBuilder3.parse(connection3.getInputStream());
		
			NodeList itemNodes1 =  doc1.getElementsByTagName("item");
			NodeList itemNodes2 =  doc2.getElementsByTagName("item");
			NodeList itemNodes3 =  doc3.getElementsByTagName("item");
			for(int i=0; i<1;i++){
	        	haeggul rec = new haeggul();
	            for(Node node1 = itemNodes1.item(i).getFirstChild(); node1!=null; node1=node1.getNextSibling()){ //첫번째 자식을 시작으로 마지막까지 다음 형제를 실행
	                 
	            	if(count > 0) // 기존에 값이 있으면 update
	            	{
	            		if(node1.getNodeName().equals("id")){	   
	 	                	sql = " update haeggul set id = ? "; 
	 	         			pstmt = con.prepareStatement(sql);
	 	         			pstmt.setString(1,node1.getTextContent());
	 	         			resultCnt = pstmt.executeUpdate();	
	 	                }
	            		if(node1.getNodeName().equals("countryName")){	   
	 	                	sql = " update haeggul set name = ? "; 
	 	         			pstmt = con.prepareStatement(sql);
	 	         			pstmt.setString(1,node1.getTextContent());
	 	         			resultCnt = pstmt.executeUpdate();	
	 	                }
	            		if(node1.getNodeName().equals("continent")){	   
	 	                	sql = " update haeggul set continent = ? "; 
	 	         			pstmt = con.prepareStatement(sql);
	 	         			pstmt.setString(1,node1.getTextContent());
	 	         			resultCnt = pstmt.executeUpdate();	
	 	                }
	            		if(node1.getNodeName().equals("basic")){	   
	 	                	sql = " update haeggul set basic = ? "; 
	 	         			pstmt = con.prepareStatement(sql);
	 	         			pstmt.setString(1,node1.getTextContent());
	 	         			resultCnt = pstmt.executeUpdate();	
	 	                } 	     
	            		if(node1.getNodeName().equals("imgUrl")){	   
	 	                	sql = " update haeggul set img = ? "; 
	 	         			pstmt = con.prepareStatement(sql);
	 	         			pstmt.setString(1,node1.getTextContent());
	 	         			resultCnt = pstmt.executeUpdate();	
	 	                }
	            	}
	            	else // 값이 없으면 insert
	            	{
	            		if(node1.getNodeName().equals("id")){	                		                	
	 	                	sql = " insert into haeggul(id) values(?); "; 
	 	         			pstmt = con.prepareStatement(sql);
	 	         			pstmt.setString(1,node1.getTextContent());
	 	         			resultCnt = pstmt.executeUpdate();	
	 	                }
	            		if(node1.getNodeName().equals("countryName")){	                	
	 	                	sql = " insert into haeggul(name) values(?); "; 
	 	         			pstmt = con.prepareStatement(sql);
	 	         			pstmt.setString(1,node1.getTextContent());
	 	         			resultCnt = pstmt.executeUpdate();	
	 	                }
	            		if(node1.getNodeName().equals("continent")){	                	
	 	                	sql = " insert into haeggul(continent) values(?); "; 
	 	         			pstmt = con.prepareStatement(sql);
	 	         			pstmt.setString(1,node1.getTextContent());
	 	         			resultCnt = pstmt.executeUpdate();	
	 	                }
	            		if(node1.getNodeName().equals("basic")){	                	
	 	                	sql = " insert into haeggul(basic) values(?); "; 
	 	         			pstmt = con.prepareStatement(sql);
	 	         			pstmt.setString(1,node1.getTextContent());
	 	         			resultCnt = pstmt.executeUpdate();	
	 	                }
	            		if(node1.getNodeName().equals("imgUrl")){	                	
	 	                	sql = " insert into haeggul(img) values(?); "; 
	 	         			pstmt = con.prepareStatement(sql);
	 	         			pstmt.setString(1,node1.getTextContent());
	 	         			resultCnt = pstmt.executeUpdate();	
	 	                }
	            	}
	            list.add(rec);
	            }
	            for(Node node2 = itemNodes2.item(i).getFirstChild(); node2!=null; node2=node2.getNextSibling()){ //첫번째 자식을 시작으로 마지막까지 다음 형제를 실행
	                 
	            	if(count > 0) // 기존에 값이 있으면 update
	            	{
	            		if(node2.getNodeName().equals("contact")){	   
	 	                	sql = " update haeggul set contact = ? "; 
	 	         			pstmt = con.prepareStatement(sql);
	 	         			pstmt.setString(1,node2.getTextContent());
	 	         			resultCnt = pstmt.executeUpdate();	
	 	                }
	            	}
	            	else // 값이 없으면 insert
	            	{
	            		if(node2.getNodeName().equals("contact")){	                	
	 	                	sql = " insert into haeggul(contact) values(?); "; 
	 	         			pstmt = con.prepareStatement(sql);
	 	         			pstmt.setString(1,node2.getTextContent());
	 	         			resultCnt = pstmt.executeUpdate();	
	 	                }
	            	}
	            list.add(rec);
	            }
	            for(Node node3 = itemNodes3.item(i).getFirstChild(); node3!=null; node3=node3.getNextSibling()){ //첫번째 자식을 시작으로 마지막까지 다음 형제를 실행
	                
	            	if(count > 0) // 기존에 값이 있으면 update
	            	{
	            		if(node3.getNodeName().equals("imgUrl2")){	   
	 	                	sql = " update haeggul set img2 = ? "; 
	 	         			pstmt = con.prepareStatement(sql);
	 	         			pstmt.setString(1,node3.getTextContent());
	 	         			resultCnt = pstmt.executeUpdate();	
	            		}
	            	}
	            	else // 값이 없으면 insert
	            	{
	            		if(node3.getNodeName().equals("imgUrl2")){	                	
	 	                	sql = " insert into haeggul(imgUrl2) values(?); "; 
	 	         			pstmt = con.prepareStatement(sql);
	 	         			pstmt.setString(1,node3.getTextContent());
	 	         			resultCnt = pstmt.executeUpdate();	
	            		}
	            	}
	            list.add(rec);
	            }
	        }
			if(pstmt != null) try{ pstmt.close(); }catch(Exception e){} 
			if(con != null) try{ con.close(); }catch(Exception e){} 
			
		}catch(Exception e){
		System.out.println("에러 :: haeggul.java : " + e.getMessage());
		StackTraceElement[] elog = e.getStackTrace();
		for(int i=0;i<elog.length;i++)
		{
			System.out.println(elog[i]);
		}			
			resultCnt = -1;
		}	
		 return list;
		}		 
	public int getCount() throws Exception{
		int count = 0;
		try{
			Class.forName(Classname);
	        con = DriverManager.getConnection(ConnectionString, Id, Password);		
			sql = "select count(*) as tcount from haeggul; "; 
  			pstmt = con.prepareStatement(sql);
  			rs = pstmt.executeQuery();	
			while(rs.next())
			{
				count = rs.getInt("tcount");
			}	
		}catch(Exception e){
			System.out.println("에러 :: haeggul.java : " + e.getMessage());
			StackTraceElement[] elog = e.getStackTrace();
			for(int i=0;i<elog.length;i++)
			{
				System.out.println(elog[i]);
			}				
		}finally {
			if(pstmt != null) try{ pstmt.close(); }catch(Exception e){} 
			if(con != null) try{ con.close(); }catch(Exception e){} 								
		}	
	return count;	
	}
}
    
 