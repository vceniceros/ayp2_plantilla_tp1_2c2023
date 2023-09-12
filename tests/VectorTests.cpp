#include "gtest/gtest.h"
#include "Vector.hpp"

class VectorTests : public ::testing::Test {
protected:
    Vector vector{};
    Item dato{};
};

TEST_F(VectorTests, Alta) {
    vector.alta(Item("1", ""));
    EXPECT_TRUE(vector[0] == "1");

    vector.alta(Item("2", ""));
    EXPECT_TRUE(vector[1] == "2");
}

TEST_F(VectorTests, AltaIndice) {
    vector.alta(Item("1", ""), 0);
    EXPECT_TRUE(vector[0] == "1");

    vector.alta(Item("2", ""), 0);
    EXPECT_TRUE(vector[0] == "2");
}

TEST_F(VectorTests, AltaIndiceManejaIndiceMayorACantidadDeDatos) {
    EXPECT_THROW(vector.alta(Item("1", ""), 1), VectorException);
}


TEST_F(VectorTests, Baja) {
    vector.alta(Item("1", ""));

    dato = vector.baja();
    EXPECT_TRUE(dato == "1");
}

TEST_F(VectorTests, BajaManejaVectorVacio) {
    EXPECT_THROW(vector.baja(), VectorException);
}

TEST_F(VectorTests, BajaIndice) {
    vector.alta(Item("1", ""));
    vector.alta(Item("2", ""));

    dato = vector.baja(0);
    EXPECT_TRUE(dato == "1");

    dato = vector.baja(0);
    EXPECT_TRUE(dato == "2");
}

TEST_F(VectorTests, BajaIndiceManejaVectorVacio) {
    EXPECT_THROW(vector.baja(0), VectorException);
}

TEST_F(VectorTests, BajaIndiceManejaIndiceMayorOIgualACantidadDeDatos) {
    vector.alta(Item("1", ""));

    EXPECT_THROW(vector.baja(1), VectorException);
}

TEST_F(VectorTests, Vacio) {
    EXPECT_TRUE(vector.vacio());

    vector.alta(Item("1", ""));
    EXPECT_FALSE(vector.vacio());

    vector.baja();
    EXPECT_TRUE(vector.vacio());
}

TEST_F(VectorTests, Tamanio) {
    EXPECT_EQ(vector.tamanio(), 0);

    vector.alta(Item("1", ""));
    vector.alta(Item("2", ""));
    vector.alta(Item("3", ""));
    EXPECT_EQ(vector.tamanio(), 3);

    vector.baja();
    EXPECT_EQ(vector.tamanio(), 2);
}

TEST_F(VectorTests, OperadorAcceso) {
    vector.alta(Item("1", ""));
    vector.alta(Item("2", ""), 0);
    vector.alta(Item("3", ""));
    dato = vector.baja(0);

    EXPECT_TRUE(vector[1] == "3");
    EXPECT_TRUE(dato == "2");
}

TEST_F(VectorTests, OperadorAccesoManejaVectorVacio) {
    EXPECT_THROW(vector[0], VectorException);
}

TEST_F(VectorTests, OperadorAccesoManejaIndiceMayorOIgualACantidadDeDatos) {
    vector.alta(Item("1", ""));

    EXPECT_THROW(vector[1], VectorException);
}