#ifndef PEOPLE_HPP
#define PEOPLE_HPP

class person {
public:
    virtual int get_id_number() =0;    
    virtual int get_age() =0;
    virtual ~person() {}
};

class college_member : public person {
public:
protected:
private:
};

class college_visitor : public person {
public:
protected:
private:
};

class student : public college_member {
public:
protected:
private:
};

class employee : public college_member {
public:
protected:
private:  
};

#endif
