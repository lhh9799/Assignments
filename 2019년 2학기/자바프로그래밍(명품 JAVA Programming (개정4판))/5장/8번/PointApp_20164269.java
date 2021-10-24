package prac05_08;

class Point {
	private int x, y;
	public Point(int x, int y) { this.x = x; this.y = y; }
	public int getX() { return x; }
	public int getY() { return y; }
	protected void move(int x, int y) { this.x = x; this.y = y; }
}
class PositivePoint extends Point {
	PositivePoint() {
		super(0, 0);
	}
	PositivePoint(int x, int y) {
		super(x, y);
		if(x < 0 || y < 0) // 만일 x나 y가 음수이면
			super.move(0, 0); // 다시 (0,0)으로 이동
	}	

	protected void move(int x, int y) { // Point의 move() 오버라이딩
		if(x > 0 && y > 0)
			super.move(x, y);
		else
			return; // 점을 이동시키지 않고 그냥 리턴
	}
	
	public String toString() {
		return "(" + getX() + "," + getY() + ")의 점";
	}
}
	public class PointApp_20164269 {
	public static void main(String[] args) {
		PositivePoint p = new PositivePoint();
		p.move(10, 10);
		System.out.println(p.toString() + "입니다.");
		
		p.move(-5, 5); // 객체 p는 음수 공간으로 이동되지 않음
		System.out.println(p.toString() + "입니다.");

		PositivePoint p2 = new PositivePoint(-10, -10);
		System.out.println(p2.toString() + "입니다.");
	}
	}