
class DualArc {
	static radius;
	static offset;
	static maxSize
	constructor( x, y, tileSize ) {
		this.x = x*tileSize;
		this.y = y*tileSize;
		this.radius = tileSize;
		this.offset = tileSize*0.5;
		this.inverted = false;
		this.maxSize = 12
		// this.linewidth = map(this.x+this.y, 0,2000, 1, this.maxSize);
		// this.dir = 1;
	}
	draw = () => {

		// if (this.linewidth <= 1 || this.linewidth >= this.maxSize) this.dir *= -1
		// this.linewidth+=this.dir*0.5
		// strokeWeight(this.linewidth)
		strokeWeight(8)
		push()
			translate(this.x, this.y)
			// push()
			// 	stroke(0);
			// 	strokeWeight(1)
			// 	ellipse(0,0,this.radius)
			// pop()
			push()
				translate(-this.offset, this.offset)
				if (this.inverted){
					rotate(PI/2)
					translate(-this.radius, 0)
				}
				arc(0,0, this.radius, this.radius, HALF_PI-PI, TWO_PI)
			pop()
			push(
				translate(this.offset, -this.offset))
				// stroke(color(0,150,150))
				if (this.inverted){
					rotate(PI/2)
					translate(this.radius, 0)
				}
				arc(0, 0, this.radius, this.radius, HALF_PI, PI)
			pop()
		pop()
	}
	invert = () => this.inverted = !this.inverted
}