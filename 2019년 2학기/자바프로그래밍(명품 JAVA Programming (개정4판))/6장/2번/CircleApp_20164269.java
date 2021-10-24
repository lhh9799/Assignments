package prac06_02;

class Circle {
	private int x, y, radius;
	
	public Circle(int x, int y, int radius) {
	this.x = x;
	this.y = y;
	this.radius = radius;
	}
	
	public String toString() {
		return "Circle(" + x + "," + y + ")반지름" + radius;
	}
	
	public boolean equals(Object obj) {
		Circle p = (Circle)obj;
		if(x == p.x && y == p.y) //두 객체의 중심(x,y)이 같으면 true리턴, 아니면 false리턴
			return true;
		else
			return false;
	}
}

class CircleApp_20164269 {

	public static void main(String[] args) {
		Circle a = new Circle(2,3,5); // 중심 (2,3)에 반지름 5인 원
		Circle b = new Circle(2,3,30); // 중심 (2,3)에 반지름 30인 원
		System.out.println("원 a : " + a);
		System.out.println("원 b : " + b);
		if(a.equals(b))
			System.out.println("같은 원");
		else
			System.out.println("서로 다른 원");

	}

}