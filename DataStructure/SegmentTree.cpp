using lnt=long long;
/* <SegmentTree> */

template<typename M>
struct SegmentTree
{
	const int n;
	std::vector<M> data;
	SegmentTree(int n) : n(n),data(n<<1,M::I()) {}
	M& operator[](int i) { return data[i+n]; } // get / pair with build
	void update(int i, const M& a) { data[i+n]=a; for(i+=n;i>1;i>>=1) data[i>>1]=M::f(data[i],data[i^1]); }
	void build() { for(int i=n-1;i>0;i--) data[i]=M::f(data[i<<1],data[i<<1|1]); }
	M fold(int l, int r) const {
		M L=M::I(),R=M::I();
		for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
			if(l&1) L=M::f(L,data[l++]);
			if(r&1) R=M::f(data[--r],R);
		}
		return M::f(L,R);
	}
};

/* <SegmentTree> */

/* <SegmentTree::Template> */
template<typename T=lnt>
struct Template
{
	T v; bool alive;
	static Template I() { return Template(); }
	Template() : alive(false) {}
	Template(T v) : v(v),alive(true) {}
	static Template f(const Template& lhs, const Template& rhs) {
		if(lhs.alive&&rhs.alive) return Template(lhs.v+rhs.v);
		return (lhs.alive)?lhs:rhs;
	}
	operator T() const { return v; }
};
/* <SegmentTree::Template> */

/* <SegmentTree::RangeSum> */
template<typename T=lnt>
struct RangeSum
{
	T v;
	static RangeSum I() { return RangeSum(0); }
	RangeSum(T v) : v(v) {}
	static RangeSum f(const RangeSum& lhs, const RangeSum& rhs) {
		return lhs+rhs;
	}
	operator T() const { return v; }
};
/* <SegmentTree::RangeSum> */

/* <SegmentTree::RangeMin> */
template<typename T=lnt>
struct RangeMin
{
	T v;
	static RangeMin I() { return RangeMin(std::numeric_limits<T>::max()); }
	RangeMin(T v) : v(v) {}
	static RangeMin f(const RangeMin& lhs, const RangeMin& rhs) {
		return std::min(lhs,rhs);
	}
	operator T() const { return v; }
};
/* <SegmentTree::RangeMin> */

/* <SegmentTree::RangeMax> */
template<typename T=lnt>
struct RangeMax
{
	T v;
	static RangeMax I() { return RangeMax(std::numeric_limits<T>::min()); }
	RangeMax(T v) : v(v) {}
	static RangeMax f(const RangeMax& lhs, const RangeMax& rhs) {
		return std::max(lhs,rhs);
	}
	operator T() const { return v; }
};
/* <SegmentTree::RangeMax> */

/* <SegmentTree::RangeMinIndex> */
template<typename T=lnt>
struct RangeMinIndex
{
	T v; int i;
	static RangeMinIndex I() { return RangeMinIndex(std::numeric_limits<T>::max()); }
	RangeMinIndex(T v, int i=-1) : v(v),i(i) {}
	static RangeMinIndex f(const RangeMinIndex& lhs, const RangeMinIndex& rhs) {
		if(lhs.v<rhs.v) return lhs; else return rhs;
	}
	operator T() const { return v; }
};
/* <SegmentTree::RangeMinIndex> */

