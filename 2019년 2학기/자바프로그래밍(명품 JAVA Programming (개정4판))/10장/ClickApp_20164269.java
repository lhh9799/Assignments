package prac10_06;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class ClickPracticeFrame extends JFrame {
	public ClickPracticeFrame() {
		super("Ŭ�� ���� �� �������α׷�");							//������ ȣ���Ͽ� Ÿ��Ʋ �ޱ�
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		//������ �����츦 ������ ���α׷� �����ϵ��� ����
		Container c = getContentPane();						//����Ʈ ���� �˾Ƴ��� Container�� ���� c�� ����
		c.setLayout(null);									//��ġ������ ����
		JLabel la = new JLabel("C");						//"C" ���ڿ��� ������ JLable ��ü ���� �Ͽ� ���� la�� ����
		la.setLocation(100, 100);							//���̺� la�� ��ġ ����
		la.setSize(20, 20);									//���̺� la�� ũ�� ����
		
		la.addMouseListener(new MyMouseAdapter());			//���콺 ������ MyMouseAdapter ��ü ����
		c.add(la);											//la�� ������ ���
		setSize(300, 300);									//������ ũ�� ����
		setVisible(true);									//ȭ�鿡 ���̱�
	}
	
	class MyMouseAdapter extends MouseAdapter {				//����Ŭ������ MyMouseAdapterŬ���� �ۼ�
		public void mousePressed(MouseEvent e) {
			JLabel la = (JLabel)e.getSource();				//�̺�Ʈ�� �߻��� �ҽ� ������Ʈ ����
			Container c = la.getParent();					//���̺��� �θ� ������Ʈ ����
			//�����̳��� ũ�� ������ ������ ���̺� ��ġ ����
			int xBound = c.getWidth() - la.getWidth();		//���̺��� ����Ʈ �� ������ ������ �ʵ��� x��ǥ�� ��� ����
			int yBound = c.getHeight() - la.getHeight();	//���̺��� ����Ʈ �� ������ ������ �ʵ��� y��ǥ�� ��� ����
			int x = (int)(Math.random()*xBound);
			int y = (int)(Math.random()*yBound);
			
			la.setLocation(x,y);
		}
	}
}

public class ClickApp_20164269 {
	public static void main(String[] args) {
		new ClickPracticeFrame();
	}
}