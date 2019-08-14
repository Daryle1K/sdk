/**
 * (c) 2019 by Mega Limited, Wellsford, New Zealand
 *
 * This file is part of the MEGA SDK - Client Access Engine.
 *
 * Applications using the MEGA API must present a valid application key
 * and comply with the the rules set forth in the Terms of Service.
 *
 * The MEGA SDK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * @copyright Simplified (2-clause) BSD License.
 *
 * You should have received a copy of the license along with this
 * program.
 */

#include <array>
#include <tuple>

#include <gtest/gtest.h>

#include <mega/utils.h>

TEST(utils, hashCombine_integer)
{
    size_t hash = 0;
    mega::hashCombine(hash, 42);
    ASSERT_EQ(2654435811u, hash);
}

TEST(utils, hashCombine_double)
{
    size_t hash = 2654435811;
    mega::hashCombine(hash, 42.);
    ASSERT_EQ(3535062602150868519u, hash);
}

TEST(utils, hashCombine_string)
{
    size_t hash = 3535062434184345740;
    mega::hashCombine(hash, std::string{"42"});
    ASSERT_EQ(14653466847519894273u, hash);
}

TEST(utils, forEach_tuple_const)
{
    const auto tup = std::make_tuple(42, 13);
    int sum = 0;
    mega::forEach(tup, [&sum](const int val)
                       {
                           sum += val;
                       });
    ASSERT_EQ(55, sum);
}

TEST(utils, forEach_tuple_mutate)
{
    auto tup = std::make_tuple(42, 13);
    mega::forEach(tup, [](int& val)
                       {
                           val *= 2;
                       });
    ASSERT_EQ(84, std::get<0>(tup));
    ASSERT_EQ(26, std::get<1>(tup));
}

TEST(utils, forEach_tuple_temporary)
{
    int sum = 0;
    mega::forEach(std::make_tuple(42, 13), [&sum](const int val)
                                           {
                                               sum += val;
                                           });
    ASSERT_EQ(55, sum);
}

TEST(utils, forEach_stdarray_const)
{
    const std::array<int, 2> arr = {42, 13};
    int sum = 0;
    mega::forEach(arr, [&sum](const int val)
                       {
                           sum += val;
                       });
    ASSERT_EQ(55, sum);
}

TEST(utils, forEach_stdarray_mutate)
{
    std::array<int, 2> arr = {42, 13};
    mega::forEach(arr, [](int& val)
                       {
                           val *= 2;
                       });
    ASSERT_EQ(84, arr[0]);
    ASSERT_EQ(26, arr[1]);
}

TEST(utils, forEach_stdarray_temporary)
{
    int sum = 0;
    mega::forEach(std::array<int, 2>{42, 13}, [&sum](const int val)
                                              {
                                                  sum += val;
                                              });
    ASSERT_EQ(55, sum);
}

TEST(utils, forEach_carray_const)
{
    const int arr[2] = {42, 13};
    int sum = 0;
    mega::forEach(arr, [&sum](const int val)
                       {
                           sum += val;
                       });
    ASSERT_EQ(55, sum);
}

TEST(utils, forEach_carray_mutate)
{
    int arr[2] = {42, 13};
    mega::forEach(arr, [](int& val)
                       {
                           val *= 2;
                       });
    ASSERT_EQ(84, arr[0]);
    ASSERT_EQ(26, arr[1]);
}

TEST(utils, forEach_carray_temporary)
{
    using Type = int[2];
    int sum = 0;
    mega::forEach(Type{42, 13}, [&sum](const int val)
                                {
                                    sum += val;
                                });
    ASSERT_EQ(55, sum);
}
