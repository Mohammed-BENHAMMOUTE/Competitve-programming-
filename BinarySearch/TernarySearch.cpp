#define EPS 1e-3
// Given a unimodal function f(x) and a range [L..R] find x such taht f(x) is minimum.
// the differenace between binary search and ternary serach is that the first devides the interval into two parts and then 
// choses which part to operate on in the next iteration, however in Ternerary Searcg, and as its name indicates, we devide the interva into three partes and we choose which two parts to choose.

// The basic idea is as follows. While binary search divides the range into two and decides
// which half to explore, ternary search divides the range into three and decide which two-
// thirds to explore. Let a unimodal function f (x) on a range [lo..hi]. Let’s take any two
// points m1 and m2 inside this range such that lo < m1 < m2 < hi. However, for simplicity
// and performance, we set delta = (hi lo)/3.0, m1 = lo + delta and m2 = hi delta so that
// m1 is approximately 13 from lo and m2 is approximately 13 from hi (or 23 from lo). Then,
// there are three possibilities:
// 1. If f (m1) > f (m2), then the minimum cannot be in the left subrange [lo..m1] and we
// should continue exploring subrange [m1..hi].
// 2. If f (m1) < f (m2), then it is the opposite of the first possibility. In this case, the
// minimum cannot be on the right subrange [m2..hi] and we should continue exploring
// subrange [lo..m2]. This scenario is shown in Figure 3.6.
// 3. If f (m1) = f (m2), a rare case, then the ternary search should be conducted in
// [m1..m2]. However, in order to simplify the code, we will just assume that f (m1) 
// f (m2) and apply the second possibility above.
// After O(log(hi lo)) steps, the range will be small enough than ✏ and we can stop.

bool Ternerary(double lo, double hi) {
	while((hi-lo) > EPS){
		double delta = (hi - lo)/3.0;
		double m1 = lo + delta;
		double m2 = lo -delta;
		(f(m1) > f(m2))? lo = m1: hi = m2;
	}
}