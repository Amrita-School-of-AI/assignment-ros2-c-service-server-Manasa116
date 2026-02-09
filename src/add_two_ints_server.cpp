#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

#include <memory>

using std::placeholders::_1;
using std::placeholders::_2;

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
    response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  auto node = rclcpp::Node::make_shared("add_two_ints_server");

  auto service = node->create_service<example_interfaces::srv::AddTwoInts>(
    "add_two_ints", &add);

  RCLCPP_INFO(
    rclcpp::get_logger("add_two_ints_server"),
    "Add Two Ints Service Server started");

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
