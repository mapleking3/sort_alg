float sqrt_bisection(float n) ///< 二分法
{
    if (n < 0)
        return n;

    float mid,last; 
    float low,up; 
    low=0,up=n; 
    mid=(low+up)/2; 
    do
    {
        if(mid*mid>n)
            up=mid; 
        else 
            low=mid;
        last=mid;
        mid=(up+low)/2; 
    }while(abs(mid-last) > eps);//精度控制
    return mid;
}

float sqrt_by_newton(float x)
{
    float val = x;
    float last;
    do {
        last = val;
        val = (val + x/val) / 2;
    } while (abs(val-last) > eps);

    return val;
}

float sqrt_inv(float x)
{
    float xhalf = 0.5f*x;
    int i = *(int*)&x; // get bits for floating VALUE 
    i = 0x5f375a86- (i>>1); // gives initial guess y0
    x = *(float*)&i; // convert bits BACK to float
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy

    return 1/x;
}

int greateast_common_divisor(int a, int b)
{
    return b > 0 ? gcd(b, a%b) : a;
}
