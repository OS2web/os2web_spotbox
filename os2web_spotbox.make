api = 2
core = 7.x

;; OS2Web projects:

; OS2Web Modules

projects[os2web_base][type] = "module"
projects[os2web_base][download][type] = "git"
projects[os2web_base][download][branch] = "develop"
projects[os2web_base][download][url] = "https://github.com/syddjurs/os2web_base.git"

;; Contrib modules below:

; Libraries

; Contrib modules

; Features + related
projects[features][subdir] = "contrib"
projects[features][version] = "2.0-beta2"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

; Panels

; Basic
projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.3"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.1"
; Patch to remove notices in badly stored features. TODO: add issue on d.o
; projects[field_group][patch][] = "patches/field_group-1.patch"

projects[file_entity][subdir] = "contrib"
projects[file_entity][version] = "2.0-unstable7"
; projects[file_entity][patch][] = "http://drupal.org/files/1553094-alt_and_title_support_for_images-175.patch"

projects[views][subdir] = "contrib"
projects[views][version] = "3.7"

projects[media][subdir] = "contrib"
projects[media][version] = "2.0-unstable7"
projects[media][patch][] = "http://drupal.org/files/media-media_browser-preview_javascript_incompatibility-1743040.patch"

projects[rules][subdir] = "contrib"
projects[rules][version] = "2.3"
