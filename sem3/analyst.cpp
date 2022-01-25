struct Point {    
    int time;                                                                                            
    int value;                                                                                           
};

// t = 1, 5, 10

std::vector<Point> sum_series(const std::vector<Point>& a, const std::vector<Point>& b) {
    std::sort(a.begin(), a.end(),
        [](const Point& lhs, const Point& rhs)                                     
        { return lhs.time < rhs.time;}                                                               
    );
                                                                                                       
    std::sort(b.begin(), b.end(),                                                                        
        [](const Point& lhs, const Point& rhs)                                                       
        { return lhs.time < rhs.time; }                                                              
    );
    
    std::size_t a_ptr = 0;
    std::size_t b_ptr = 0;
    std::vector<Point> sum;
    while (a_ptr < a.size() && b_ptr < b.size()) {
        if (a[a_ptr].time > b[b_ptr].time){
            sum.push_back(b[b_ptr]);
            ++b_ptr;
        } else if (a[a_ptr].time < b[b_ptr].time) {
            sum.push_back(a[a_ptr]);
            ++a_ptr;
        } else {
            Point sum_values = {
                .time = a[a_ptr].time,
                .value = a[a_ptr].value + b[b_ptr].value
            };
            sum.push_back(sum_values);
            ++a_ptr;
            ++b_ptr;
        }
    }
    
    if (b_ptr != b.size()) {
        for (std::size_t i = b_ptr; i < b.size(); ++i) {
            sum.push_back(b[i]);
        }
    } else {
        for (std::size_t i = a_ptr; i < a.size(); ++i) {
            sum.push_back(a[i]);
        }
    }
    
    return sum;
} 





