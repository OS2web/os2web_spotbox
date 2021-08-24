# OS2Web Spotbox Drupal module

## Module purpose

This module provides the Spotbox entity with all required UI to create/update/remove
spotboxes in Drupal. Additionally, module provides preconfigured paragraphs for
spotboxes to add them as reference in [OS2Web pagebuilder module](https://github.com/OS2web/os2web_pagebuilder)
or others where paragraph is used as entity reference.

Spotboxes are available in different types. Depends on chosen type proper set
of fields are shown for storing the spotbox information.

Module does not provide theme for spotboxes design.
It should be implementer separately.

## Install

1. Module is available to download via composer.
    ```
    composer require os2web/os2web_spotbox
    drush en os2web_spotbox
    ```
2. After module has been enabled you call manage Spotbox entities by path `/admin/content/os2web_spotbox`

## Update
Updating process for OS2Web Spotbox module is similar to usual composer package.
Use Composer's built-in command for listing packages that have updates available:

```
composer outdated os2web/os2web_spotbox
```

## Contribution

Project is opened for new features and os course bugfixes.
If you have any suggestion, or you found a bug in project, you are very welcome
to create an issue in github repository issue tracker.
For issue description there is expected that you will provide clear and
sufficient information about your feature request or bug report.

### Code review policy
See [OS2Web code review policy](https://github.com/OS2Web/docs#code-review)

### Git name convention
See [OS2Web git name convention](https://github.com/OS2Web/docs#git-guideline)
