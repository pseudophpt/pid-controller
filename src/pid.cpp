class pid {
    private:
        /* Desired value */
        float set_point;
        
        /* Constants */
        float weight_p;
        float weight_i;
        float weight_d;
        
        /* Integral over whole period of time */
        float integral_total;
        
        /* Previous error value */
        float error_prev;
        
    public:
        pid (float set_point, float weight_p, float weight_i, float weight_d);
        
        float get_weight_p (void);
        float get_weight_i (void);
        float get_weight_d (void);
        
        void set_weight_p (float weight_p);
        void set_weight_i (float weight_i);
        void set_weight_d (float weight_d);
        
        float iterate (float measurement, float time); 
};

/* Class constructor */
pid::pid (float set_point, float weight_p, float weight_i, float weight_d) {
    /* Initialize class members */
    this->set_point = set_point;
    this->weight_p = weight_p;
    this->weight_i = weight_i;
    this->weight_d = weight_d;
    
    integral_total = 0.0F;
    error_prev = 0.0F;
}

/* Getters */
float pid::get_weight_p (void) {
    return weight_p;
}

float pid::get_weight_i (void) {
    return weight_i;
}

float pid::get_weight_d (void) {
    return weight_d;
}

/* Setters */
void pid::set_weight_p (float weight_p) {
    this->weight_p = weight_p;
}

void pid::set_weight_i (float weight_i) {
    this->weight_i = weight_i;
}

void pid::set_weight_d (float weight_d) {
    this->weight_d = weight_d;
}

/* Calculates best course of action based on previous results */
float pid::iterate (float measurement, float time) {
    /* The 3 controllers */
    float p;
    float i;
    float d;
    
    /* Error function */
    float error = set_point - measurement;
    
    /* Add to integral */
    integral_total += (error * time);
    
    /* Proportion controller */
    p = weight_p * error;
    
    /* Integral controller */
    i = weight_i * integral_total;
    
    /* Derivative controller */
    d = weight_d * (error - error_prev) / time;
    
    float total = p + i + d;
    
    /* Update previous values */
    error_prev = error;
    
    return total;
}

int main () {

}
