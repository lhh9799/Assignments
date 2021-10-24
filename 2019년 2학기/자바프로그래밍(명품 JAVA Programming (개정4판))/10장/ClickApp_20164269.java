package prac10_06;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class ClickPracticeFrame extends JFrame {
	public ClickPracticeFrame() {
		super("클릭 연습 용 응용프로그램");							//생성자 호출하여 타이틀 달기
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		//프레임 윈도우를 닫으면 프로그램 종료하도록 설정
		Container c = getContentPane();						//컨텐트 팬을 알아내서 Container형 변수 c에 저장
		c.setLayout(null);									//배치관리자 삭제
		JLabel la = new JLabel("C");						//"C" 문자열을 가지는 JLable 객체 생성 하여 변수 la에 저장
		la.setLocation(100, 100);							//레이블 la의 위치 설정
		la.setSize(20, 20);									//레이블 la의 크기 설정
		
		la.addMouseListener(new MyMouseAdapter());			//마우스 리스너 MyMouseAdapter 객체 생성
		c.add(la);											//la에 리스너 등록
		setSize(300, 300);									//프레임 크기 설정
		setVisible(true);									//화면에 보이기
	}
	
	class MyMouseAdapter extends MouseAdapter {				//내부클래스로 MyMouseAdapter클래스 작성
		public void mousePressed(MouseEvent e) {
			JLabel la = (JLabel)e.getSource();				//이벤트가 발생한 소스 컴포넌트 구함
			Container c = la.getParent();					//레이블의 부모 컴포넌트 구함
			//컨테이너의 크기 내에서 랜덤한 레이블 위치 설정
			int xBound = c.getWidth() - la.getWidth();		//레이블이 컨텐트 팬 밖으로 나가지 않도록 x좌표의 경계 설정
			int yBound = c.getHeight() - la.getHeight();	//레이블이 컨텐트 팬 밖으로 나가지 않도록 y좌표의 경계 설정
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