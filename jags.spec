%define name	jags
%define version	0.22.1
%define release 1

Summary:	Just Another Gtk+ Samba-client
Name:		%{name}
Version: 	%{version}
Release: 	%{release}
License: 	GPL
Group: 		System/Tools
URL: 		http://jags.sourceforge.net
Source: 	http://prdownloads.sourceforge.net/%{name}/%{name}-%{version}.tar.gz
BuildRoot: 	%{_tmppath}/%{name}-%{version}-%{release}-buildroot
Packager:	Brixton Linux Action Group

%description
Jags - Just Another Gtk+ Samba-client, is a GUI frontend running over Samba
and Smbmount. It's easy to use and very configurable.

%prep
rm -rf $RPM_BUILD_ROOT
%setup -n %{name}-%{version} 

%build
%configure
make


%install
%makeinstall PREFIX=$RPM_BUILD_ROOT/usr
strip -s $RPM_BUILD_ROOT/%{_bindir}/jags || :
cp upgrade $RPM_BUILD_ROOT/%{_bindir}/jags-upgrade

%clean
rm -rf $RPM_BUILD_ROOT

%post

%postun

%files
%defattr(-,root,root,0755)
%doc AUTHORS BUGS CHANGES ChangeLog COPYING INSTALL NEWS README TODO UPGRADE VERSION
%{_datadir}/%{name}/* 
%{_bindir}/*

%changelog
* Sun Apr 20 2003 moe <moe@blagblagblag.org>
- initial specfile

