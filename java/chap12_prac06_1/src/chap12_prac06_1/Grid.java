package chap12_prac06_1;

import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Grid extends JFrame {
	public Grid() {
		super("격자 그리기");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setContentPane(new MyPanel());
		setSize(300,300);
		setVisible(true);
	}
	
	class MyPanel extends JPanel {
		@Override
		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			int dw = getWidth()/10;
			for(int i=1; i<=9; i++)
				g.drawLine(i*dw,  0, i*dw, getHeight()); // 수직선
			int dh = getHeight()/10;			
			for(int i=1; i<=9; i++)
				g.drawLine(0, i*dh, getWidth(), i*dh); //  수평선 
		}
	}
	public static void main(String[] args) {
		new Grid();
	}
}

