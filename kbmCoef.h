#include <string>

struct KbmCoefficient
{
        std::string class_;
        double coef_;
        std::string payment0;
        std::string payment1;
        std::string payment2;
        std::string payment3;
        std::string paymentOver3;

        bool operator<(const KbmCoefficient &r) const {
                if (class_ == r.class_) return true;
                if (class_ == "M") return true;
                if (r.class_ == "M") return false;

                int lv = atoi(class_.c_str());
                int rv = atoi(r.class_.c_str());

                return lv < rv;
        }

        KbmCoefficient& operator=(const KbmCoefficient& other)
        {
                // check for self-assignment
                if(&other == this)
                    return *this;

                class_ = other.class_;
                coef_ = other.coef_;
                payment0 = other.payment0;
                payment1 = other.payment1;
                payment2 = other.payment2;
                payment3 = other.payment3;
                paymentOver3 = other.paymentOver3;

                return *this;
    }
};
