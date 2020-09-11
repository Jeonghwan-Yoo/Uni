package chap11_prac06;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.text.BadLocationException;

public class TextAreaPracticeFrame extends JFrame {
	private JTextArea ta = new JTextArea(5,10); // 5행 10열
	private JSlider slider = new JSlider(0,100,0);
	
	public TextAreaPracticeFrame() {
		super("TextArea Practice Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new BorderLayout());
		c.add(slider, BorderLayout.CENTER);
		c.add(new JScrollPane(ta), BorderLayout.NORTH); // 스크롤이 되도록 함
		
		// 슬라이더의 속성 설정
		slider.setMajorTickSpacing(20);
		slider.setMinorTickSpacing(5);
		slider.setPaintLabels(true);
		slider.setPaintTicks(true);
		
		slider.addChangeListener(new ChangeListener() {
			@Override
			public void stateChanged(ChangeEvent e) {
				JSlider s = (JSlider)e.getSource();
				if(ta.getText().length() <= s.getValue()) // 슬라이더를 글자보다 더 많이 움직인 경우
					s.setValue(ta.getText().length()); // 글자수 크기에 맞추어 슬라이더 조절
				else {
					try {
						ta.setText(ta.getText(0, s.getValue()));
					} catch (BadLocationException e1) {}
				}
			}
		});
	
		ta.addKeyListener(new KeyAdapter() {
			@Override
			public void keyTyped(KeyEvent e) {
				JTextArea t = (JTextArea)e.getSource();
				int size = t.getText().length(); // 현재 텍스트영역에 입력된 글자수
				try {
				if(size >= 100) // 이미 100개 이상이라면
					t.setText(t.getText(0, 100));
				} catch(BadLocationException ex) {}
				
				slider.setValue(size); // 슬라이더의 값 변경. 슬라이더의 손잡이가 움직임
			}
		});

		setSize(300,200);
		setVisible(true);
	}
	public static void main(String[] args) {
		new TextAreaPracticeFrame();
	}
}

