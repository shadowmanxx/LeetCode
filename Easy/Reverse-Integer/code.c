int reverse(int x) {
    
    long long val = 0;
    
    while(x)
    {
        val = val*10 + x%10;
        x /= 10;
    }
    
    return (val > 2147483647 || val < -2147483647) ? 0:val;
}
