package prac09_04;
import javax.swing.*;
import java.awt.*;

class TenColorButtonFrame extends JFrame{
	public TenColorButtonFrame() {
		super("Ten Color Buttons Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		
		GridLayout grid = new GridLayout(1, 10);
		c.setLayout(grid);
		
		JButton btn[] = new JButton[10];
		Color [] color = { Color.RED, Color.ORANGE, Color.YELLOW,
				Color.GREEN, Color.CYAN, Color.BLUE, Color.MAGENTA, Color.GRAY,
				Color.PINK, Color.LIGHT_GRAY };
		
		for(int i=0; i<btn.length; i++) {
			btn[i] = new JButton(Integer.toString(i));
			btn[i].setOpaque(true);
			btn[i].setBackground(color[i]);
			c.add(btn[i]);
		}
		setSize(500, 200);
		setVisible(true);
	}
}

public class TenColorApp_20164269 {
	public static void main(String[] args) {
		new TenColorButtonFrame();
	}
}