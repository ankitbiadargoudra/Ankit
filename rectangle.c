
int premin(int * h, int pos)
{
    int count=0;
    for(int i =pos; i>=0;i-- )
    {
        if(h[pos]<=h[i])
        {
            count++;
        }
        else{
            break;
        }
    }
    return count;
}

int nextmin(int * h, int pos, int size)
{
    int count=0;
    for(int i =pos; i<size;i++ )
    {
        if(h[pos]<=h[i])
        {
            count++;
        }
        else{
            break;
        }
    }
    return count;
}
long largestRectangle(int h_count, int* h) {

    long area =0;
    for(int i=0;i<h_count;i++)
    {
        int width = premin(h,i)+ nextmin(h,i,h_count)- 1;
        int length = h[i];
        
        long  cur_area = width*length;
        if(cur_area>area)
        {
          area= cur_area;   
        }
        
    }
    return area;
    
}
