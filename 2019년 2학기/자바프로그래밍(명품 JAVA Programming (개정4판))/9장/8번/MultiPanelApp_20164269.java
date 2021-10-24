package prac09_08;
import javax.swing.*;
import java.awt.*;


class NorthPanel extends JPanel {
	public NorthPanel() {
		setBackground(Color.LIGHT_GRAY);
		setVisible(true);
		setLayout(new FlowLayout(FlowLayout.CENTER));
		add(new JButton("열기"));
		add(new JButton("닫기"));
		add(new JButton("나가기"));
	}
}

class SouthPanel extends JPanel {
	public SouthPanel() {
		setBackground(Color.YELLOW);
		setVisible(true);
		setLayout(new FlowLayout(FlowLayout.LEFT));
		add(new JButton("Word Input"));
		add(new JTextField(15));
	}
}

class CenterPanel extends JPanel {
	public CenterPanel() {
		setBackground(Color.WHITE);
		setLayout(null);
		for(int i=0; i<10; i++) {
			JLabel j = new JLabel("*");
			int x = (int)(Math.random()*250)+10;
			int y = (int)(Math.random()*200)+10;
			j.setLocation(x,y);
			j.setSize(20,20);
			j.setForeground(Color.RED);
			add(j);
		}
	}
}

class MultiPanelFrame extends JFrame {
	public MultiPanelFrame() {
		super("여러 개의 패널을 가진 프레임");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.add(new NorthPanel(), BorderLayout.NORTH);
		c.add(new SouthPanel(), BorderLayout.SOUTH);
		c.add(new CenterPanel(), BorderLayout.CENTER);
		
		setSize(320,320);
		setVisible(true);
	}
}

public class MultiPanelApp_20164269 {

	public static void main(String[] args) {
		new MultiPanelFrame();
	}
}