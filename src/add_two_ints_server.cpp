#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

#include <memory>

void add(
  const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
  std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response)
{
  response->sum = request->a + request->b;

  RCLCPP_INFO(
    rclcpp::get_logger("add_two_ints_server"),
    "Incoming request: a=%ld, b=%ld",
    request->a, request->b);

  RCLCPP_INFO(
    rclcpp::get_logger("add_two_ints_server"),
    "Sending response: sum=%ld",
    response
