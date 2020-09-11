package chap12_prac10;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ImagePracticeFrame extends JFrame {
	public ImagePracticeFrame(){
		super("그래픽 이미지 연습");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		setContentPane(new MyPanel());
		setSize(300,300);
		setVisible(true);
	}
	
	class MyPanel extends JPanel {
		private ImageIcon icon = new ImageIcon("images/back.jpg");		
		private Image img = icon.getImage();
		private int imgWidth = img.getWidth(this);
		private int imgHeight = img.getHeight(this);
	
		@Override
		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			int panelWidth = this.getWidth();
			int panelHeight = this.getHeight();
			
			g.drawImage(img, 0, 0, panelWidth/2-5, panelHeight/2-5, 0, 0, imgWidth/2, imgHeight/2, this);
			g.drawImage(img, panelWidth/2+5, 0, panelWidth, panelHeight/2-5, imgWidth/2, 0, imgWidth, imgHeight/2, this);
			g.drawImage(img, 0, panelHeight/2+5, panelWidth/2-5, panelHeight, 0, imgHeight/2, imgWidth/2, imgHeight, this);
			g.drawImage(img, panelWidth/2+5, panelHeight/2+5, panelWidth, panelHeight, imgWidth/2, imgHeight/2, imgWidth, imgHeight, this);
		}
	}
	
	static public void main(String[] args) {
		new ImagePracticeFrame();
	}
}

