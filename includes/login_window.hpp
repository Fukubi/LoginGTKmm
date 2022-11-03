#ifndef LOGIN_WINDOW_HPP
#define LOGIN_WINDOW_HPP

#include <gtkmm/application.h>
#include <gtkmm/button.h>
#include <gtkmm/dialog.h>
#include <gtkmm/entry.h>
#include <gtkmm/grid.h>
#include <gtkmm/window.h>

class LoginWindow : public Gtk::Window {
private:
  bool isLogged;

  Gtk::Grid mainGrid;
  Gtk::Label usernameLabel;
  Gtk::Label passwordLabel;
  Gtk::Entry usernameInput;
  Gtk::Entry passwordInput;

  Gtk::Button loginBtn;

  Gtk::Dialog onLoginDialog;

  Gtk::Label onLoginDialogLabel;

public:
  LoginWindow();

  void setupHierarchy();
  void initializeChildrens();
};

#endif // !LOGIN_WINDOW_HPP
