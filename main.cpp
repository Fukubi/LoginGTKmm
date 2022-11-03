#include "login_window.hpp"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
  auto application =
      Gtk::Application::create(argc, argv, "org.login-application");
  LoginWindow window;

  return application->run(window);
}
