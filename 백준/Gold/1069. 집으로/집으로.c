int main()
{
    int x, y, d, t;
    scanf("%d %d %d %d", &x, &y, &d, &t);
    double distance = sqrt((x * x) + (y * y));
    double D_ = distance;
    double extime=0;
    double time = 0;
    time = distance;
    while (1)
    {
        if (D_ < d)
        {
            if (d - D_ + t > D_)
                extime += D_;
            else
                extime += d - D_ + t;
            break;

        }
        else
        {
            D_ = D_ - d;
            extime += t;
        }
    }
    if (extime < time)
        time = extime;
    extime = 0;
    D_ = 2 * d;
    extime += 2 * t;
    while (1)
    {
        if (D_ < distance)
        {
            D_ += d;
            extime += t;
            continue;
        }
        else if (D_ == distance)
        {
            extime = time;
            break;
        }
        else if (D_ > distance)
            break;
    }
    if(extime<time)
        time = extime;

    printf("%.10lf", time);
}