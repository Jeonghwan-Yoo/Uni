package chap09_prac08;

import java.awt.*;
import javax.swing.*;

public class MultiPanelFrame extends JFrame {
	public MultiPanelFrame() {
		super("여러 개의 패널을 가진 프레임");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane(); // 컨텐트팬은 디폴트로 BorderLayout 배치 관리자.
		
		c.add(new SouthPanel(), BorderLayout.SOUTH);
		c.add(new CenterPanel(), BorderLayout.CENTER);
		c.add(new NorthPanel(), BorderLayout.NORTH);
		setSize(300,300);
		setVisible(true);
	}
	public static void main(String[] args) {
		new MultiPanelFrame();
	}

}

class SouthPanel extends JPanel {
	public SouthPanel() {
		setBackground(Color.YELLOW);
		setOpaque(true);
		setLayout(new FlowLayout(FlowLayout.LEFT)); // JPanel이 디폴트로 FlowLayout이지만, 확실히 하기 위해
		add(new JButton("Word Input"));
		add(new JTextField(15));
	}
}
class CenterPanel extends JPanel {
	public CenterPanel() {
		setBackground(Color.WHITE);
		setLayout(null); // 배치관리자 없음
		for(int i=0; i<10; i++) {
			JLabel l = new JLabel("*");
			l.setSize(20,20);
			l.setForeground(Color.RED);
			l.setLocation((int)(Math.random()*250+10), (int)(Math.random()*200+10));
			
			add(l);
		}
	}
}
class NorthPanel extends JPanel {
	public NorthPanel() {
		setBackground(Color.LIGHT_GRAY);
		setOpaque(true);
		setLayout(new FlowLayout()); // JPanel이 디폴트로 FlowLayout이지만, 확실히 하기 위해		
		add(new JButton("열기"));
		add(new JButton("닫기"));
		add(new JButton("나가기"));
	}
}