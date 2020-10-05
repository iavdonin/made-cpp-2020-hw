#pragma once
#include <iostream>
#include <vector>

namespace task {

using std::vector;

vector<double> operator+(const vector<double> &a, const vector<double> &b) {
  size_t n = a.size();
  vector<double> c(n);
  for (size_t i = 0; i < n; ++i) {
    c[i] = a[i] + b[i];
  }
  return c;
}

vector<double> operator+(const std::vector<double> &a) { return a; }

vector<double> operator-(const vector<double> &a, const vector<double> &b) {
  size_t n = a.size();
  vector<double> c(n);
  for (size_t i = 0; i < n; ++i) {
    c[i] = a[i] - b[i];
  }
  return c;
}

vector<double> operator-(const std::vector<double> &a) {
  vector<double> b(a.size());
  for (size_t i = 0; i < a.size(); ++i) {
    b[i] = -a[i];
  }
  return b;
};

double operator*(const vector<double> &a, const vector<double> &b) {
  double scalar_product = 0.;
  for (size_t i = 0; i < a.size(); ++i) {
    scalar_product += a[i] * b[i];
  }
  return scalar_product;
}

vector<double> operator%(const vector<double> &a, const vector<double> &b) {
  vector<double> c(3);
  c[0] = a[1] * b[2] - a[2] * b[1];
  c[1] = -(a[0] * b[2] - a[2] * b[0]);
  c[2] = a[0] * b[1] - a[1] * b[0];
  return c;
}

bool operator||(const vector<double> &a, const vector<double> &b) {
  const double eps = 1e-10;
  double ratio = a[0] / b[0];
  for (size_t i = 1; i < a.size(); ++i) {
    if (a[i] / b[i] > ratio + eps || a[i] / b[i] < ratio - eps) {
      return false;
    }
  }
  return true;
}

bool operator&&(const vector<double> &a, const vector<double> &b) {
  if (a || b) {
    return a[0] * b[0] > 0;
  }
  return false;
}

std::istream &operator>>(std::istream &in, vector<double> &a) {
  a.clear();
  int n;
  double tmp;
  in >> n;
  for (size_t i = 0; i < n; ++i) {
    in >> tmp;
    a.push_back(tmp);
  }
  return in;
}

std::ostream &operator<<(std::ostream &out, const vector<double> &a) {
  for (size_t i = 0; i < a.size(); ++i) {
    out << a[i] << " ";
  }
  out << "\n";
  return out;
}

void reverse(vector<double> &a) {
  double tmp;
  size_t n = a.size();
  for (size_t i = 0; i < n / 2; ++i) {
    tmp = a[i];
    a[i] = a[n - i - 1];
    a[n - i - 1] = tmp;
  }
}

vector<int> operator|(const vector<int> &a, const vector<int> &b) {
  vector<int> c(a.size());
  for (size_t i = 0; i < a.size(); ++i) {
    c[i] = a[i] | b[i];
  }
  return c;
}

vector<int> operator&(const vector<int> &a, const vector<int> &b) {
  vector<int> c(a.size());
  for (size_t i = 0; i < a.size(); ++i) {
    c[i] = a[i] & b[i];
  }
  return c;
}
} // namespace task
